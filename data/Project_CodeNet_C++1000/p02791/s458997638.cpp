#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;
typedef long long ll;

int main(){
    int N;cin >> N;
    vector<int> num_list(N);
    int count = 0;
    int min = 0;
    rep(i,N){
        int tmp;
        cin >> tmp;
        num_list.push_back(tmp);
        if (count == 0){
            min = tmp;
            count++; 
            continue;
        }
        if (tmp <= min){
            min = tmp;
            count++;
        }
    }
    cout << count << endl;

    return 0;
}