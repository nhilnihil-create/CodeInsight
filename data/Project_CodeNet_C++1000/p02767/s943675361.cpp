#include <bits/stdc++.h>
#define rep(i,n) for(int i = 1; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    vector<int> list;
    int ans;
    rep (i,N + 1){
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
        //cout << tmp << endl;
    }
    int min = 1000000000;
    rep (i,101){
        int count = 0;
        int tmp = 0;
        for (int j = 0; j < N; j++){
            tmp = abs(list[j] - i);
            count += pow(tmp,2);
            //cout << "cout=" << count << endl;
        } 
        if (count < min){
            min = count;
            //cout << i << endl;
        }
    }
    cout << min << endl;
    return 0;
}