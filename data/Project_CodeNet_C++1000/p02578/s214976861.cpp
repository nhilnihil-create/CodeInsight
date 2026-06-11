
    #include <bits/stdc++.h>
    #define rep(i,a,b) for(int i=(a);i<(b);i++)
    #define per(i,a,b) for(int i=(a);i>(b);i--)
    typedef long long ll;
    using namespace std;

    typedef double dd;

    int main(){
         ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];

    rep(i,0,n){
        cin>>arr[i];
    }
    ll sum=0; int top =arr[0];
    rep(i,0,n){if(i==n-1) continue;
        if(arr[i+1]>=arr[i]){continue;}
        if(arr[i]>arr[i+1]){
            sum+=(arr[i]-arr[i+1]);
            arr[i+1]=arr[i];
        }
    }
       cout<<sum;

        return 0;
    }
