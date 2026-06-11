#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 + (int) 2.0e5; 

int main(){
    int N;
    int Anum[MAXN]={};
    cin >> N;
    int A[N];
    int Amax=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        Anum[A[i]]++; 
        Amax=max(Amax,A[i]);
    }

    long long sum=0;
    long long ans;

    for(int i=1; i<MAXN; i++){
        sum += ( (long long) Anum[i]) * ( ( (long long) Anum[i] )-1ll)/2ll;
        //if(i<=Amax) cout << "i Anum[i] sum " << i << " " << Anum[i] << " " << sum << endl;
        //if(i%100000==0) cout << "i Anum[i] sum " << i << " " << Anum[i] << " " << sum << endl;
    }

    //cout << "sum " << sum << endl;

    for(int i=0; i<N; i++){
        ans = sum - ( (long long) Anum[A[i]]) * ( ( (long long) Anum[A[i]] )-1ll)/2ll + ( ( (long long) Anum[A[i]] ) - 1ll) * ( ( (long long) Anum[A[i]] )-2ll)/2ll;
        cout << ans << endl;
    }
    
    return 0;
}