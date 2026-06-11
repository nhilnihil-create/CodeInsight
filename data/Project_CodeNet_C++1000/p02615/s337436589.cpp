    #include<bits/stdc++.h>
    #define rep(i, n) for(int i=0; i<n; i++)
    using namespace std;
    using ll = long long;
    using P = pair<int, int>;

    int main(){
        ll N;
        cin >> N;
        ll A[N];
        rep(i, N) cin>>A[i];

        sort(A, A+N);

        ll ans=0;
        ll conf=0;
        ll conf_pre=0;
        queue<ll> q;
        rep(i, N){
            if(i==0){
                q.push(A[N-i-1]);
                continue;
            }else{
                if(i%2==0 || i==1){
                    conf_pre=q.front();
                    q.pop();
                }
                conf=A[N-i-1];
                //cout<<conf_pre<<endl;
                ans+=conf_pre;
                q.push(A[N-i-1]);
            }
        }
        cout<<ans<<endl;
        return 0;
    }