#include<bits/stdc++.h>
using namespace std;

int main(){
    int64_t N;
    cin >> N;
    int top = sqrt(N);
    map<int, int> soinsu;
    int i = 2;
    bool flag = false;
    if(N == 1) flag = true;
    while(i<=top){
        if(N % i == 0){
            if(soinsu.count(i) > 0) soinsu.at(i) += 1;
            else soinsu[i] = 1;
            N /= i;
            top = sqrt(N);
        }
        else{
            i++;
        }
    }
    if(N != 1){
       if(soinsu.count(N) > 0) soinsu.at(N) += 1;
        else soinsu[N] = 1;
    }

    if(flag) cout << 0 << endl;
    else if(soinsu.size() == 0) cout << 1 << endl;
    else{
        int count=0;
        int t;
        for(auto itr = soinsu.begin(); itr != soinsu.end(); ++itr) {
            t = 1;
            while(true){
                if(itr->second < t) break;
                else{
                    itr->second -= t;
                    t++;
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}