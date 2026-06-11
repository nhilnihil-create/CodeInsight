#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N;
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=0;k<10;k++){
                if(((i>>k)&1) != ((j>>k)&1)){
                    cout<<(k+1)<<" ";
                    break;
                }
            }
        }
        if(i==N) break;
        cout<<endl;
    }
    return 0;
}