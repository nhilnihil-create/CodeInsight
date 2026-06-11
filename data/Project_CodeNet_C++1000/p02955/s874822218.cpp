#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vec<int> A(N);
    int sum = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }
    auto check = [&](int M){
        vec<int> B(N);
        for(int i=0;i<N;i++) B[i] = A[i]%M;
        sort(B.begin(),B.end());
//        cerr << M << "\n";
//        for(int i=0;i<N;i++) cerr << B[i] << (i!=N-1? " ":"\n");
        int l = 0,r = N-1;
        int c = 0;
        while(l<r){
            int a = B[l],b = M-B[r];
            if(a<b){
                B[r] += a;
                B[l] = 0;
                c += a;
                l++;
            }else if(a>b){
                B[l] -= b;
                B[r] = 0;
                c += b;
                r--;
            }else{
                c += a;
                B[l] = B[r] = 0;
                l++; r--;
            }
        }
        bool ok = true;
        for(int i=0;i<N;i++) ok &= B[i]==0;
        return ok && (c<=K);
    };

    int ans = 1;
    for(int i=1;i*i<=sum;i++) if(sum%i==0){
        if(check(i)) ans = max(ans,i);
        if(check(sum/i)) ans = max(ans,sum/i);
    }
    cout << ans << "\n";
}