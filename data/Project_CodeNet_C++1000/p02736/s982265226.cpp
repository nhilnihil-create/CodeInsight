#include <iostream>
#include <string>
using namespace std;

int a[1000010], sum[1000010];

int main(void){
    int N;
    string S;
    cin >> N >> S;
    bool oneexists=false;
    for(int i=0; i<N; ++i){
        a[i]=S[i]-'1';
        oneexists=oneexists||(a[i]==1);
    }
    sum[0]=0;
    for(int i=1; i<N; ++i){
        sum[i]=sum[i-1];
        int t=i;
        while(t%2==0){
            t /= 2;
            ++sum[i];
        }
    }
    int ans=0;
    if(oneexists){
        for(int i=0; i<N; ++i){
            if(sum[N-1]==sum[i]+sum[N-1-i]){
                (ans += a[i]) %= 2;
            }
        }
    }
    else{
        for(int i=0; i<N; ++i){
            if(sum[N-1]==sum[i]+sum[N-1-i]){
                (ans += a[i]/2) %= 2;
            }
        }
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}
