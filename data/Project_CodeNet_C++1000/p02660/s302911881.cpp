#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    long long n,ans=0;
    cin>>n;
    vector<int>p(1000000);
    int req,cnt;
    for(int i=2;i<1000000;i++){
        if(p[i]!=-1){
            req=1;
            cnt=0;
            for(int j=i*2;j<1000000;j+=i){
                p[j]=-1;
            }
            while(n%i==0){
                cnt++;
                if(cnt==req){
                    cnt=0;
                    req++;
                    ans++;
                }
                n/=i;
            }
        }
    }
    if(n>1)ans++;
    cout<<ans;
	return 0;
}
