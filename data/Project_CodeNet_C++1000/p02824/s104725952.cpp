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
    vector <int> lastOccurence(N);
    for (int i=0; i<N; ++i)
    {
        int j=i;
        for (; j<N; ++j)
        {
            if (A[j]!=A[i]) {
                break;
            }
        }
        for (int k=i; k<j; ++k) lastOccurence[k]=j-1;
        i=j-1;
    }
    ll ans=P;
    ll cindex=N-P-1;
    while (cindex>=0)
    {
        int index=lastOccurence[cindex];
        if (index>N-P-1) ans++;
        else if (A[index]+M<A[N-P]) break;
        else if ((P+index)>=V) ans++;
        else  {
            int balance=V-(P+index);
            ll tsum = pfxsum[N-P]-pfxsum[index];
            ll ub=A[index]+M;
            // cout << index << " " << balance << " " << tsum << " " << ub << "\n";
            if ((N-P-index)*ub - tsum >= balance*M ) ans++; 
            // if (index+balance < N-P-balance+1)
            // {
            //     int ub = A[index]+M-A[N-P];
            //     int lb = A[index+balance]-A[index];
            //     if (!(lb>ub)) ans++;
            // }
        }
        cindex--;
    }
    cout << ans << "\n";
    return 0;
}