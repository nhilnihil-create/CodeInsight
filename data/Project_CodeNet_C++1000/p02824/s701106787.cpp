#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,V,P; cin >> N >> M >> V >> P;
    vector <ll> A(N);
    vector <ll> pfxsum(N);
    loop(i,0,N) cin >> A[i];
    sort(A.begin(), A.end());
    pfxsum[0]=A[0];
    loop(i,1,N) pfxsum[i]=pfxsum[i-1]+A[i];
    ll ans=P;
    ll index=N-P-1;
    while (index>=0)
    {
        if (index>N-P-1) ans++;
        else if (A[index]+M<A[N-P]) break;
        else if ((P+index)>=V) ans++;
        else  {
            int balance=V-(P+index);
            ll tsum = pfxsum[N-P]-pfxsum[index];
            ll ub=A[index]+M;
            if ((N-P-index)*ub - tsum >= balance*M ) ans++; 
        }
        index--;
    }
    cout << ans << "\n";
    return 0;
}