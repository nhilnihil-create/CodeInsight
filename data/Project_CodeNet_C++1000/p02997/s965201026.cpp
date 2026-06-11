#include<bits/stdc++.h>
using ll = long long;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<vector<int>> hen(n);
    if(k > (n - 1) * (n - 2) / 2){cout << -1 << endl; return 0;}

    for(int i = 1; i < n; i++){
        hen[0].push_back(i);
        hen[i].push_back(0);
    }

    int cnt = 0; //cnt < ((n - 1)(n - 2) / 2 - k)
    int lim = ((n - 1) * (n - 2) / 2) - k;

    for(int i = 1; i < n && cnt < lim; i++){
        for(int j = i + 1; j < n && cnt < lim; j++){
            hen[i].push_back(j);
            hen[j].push_back(i);
            cnt++;
        }
    }
    std::cout << lim + n - 1<< std::endl;
    for(int i = 0; i < n; i++){
        for(auto j : hen[i]){
            if(i < j){
                std::cout << i + 1<< " " << j + 1 << std::endl;
            }
        }
    }
}
