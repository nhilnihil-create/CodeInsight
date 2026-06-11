#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N, K; cin >> N >> K;
    vll A(N), F(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> F[i];
    }
    sort(A.begin(),A.end());
    sort(F.begin(),F.end(),greater<ll>());
    bool a=false, b=false;
    ll min = 0; ll max = 1000000000001; ll mid = (max+min)/2;

    ll k; ll mid2;
    ll t = 0;
    while(a==true&&b==true||a==false&&b==false){
        k = 0;

        for(int i=0; i<N; i++){
            if(F[i]*A[i]>mid){
                k += (F[i]*A[i]-mid)/F[i];
                if((F[i]*A[i]-mid)%F[i] != 0){
                    k++;
                }
            }
        }
        if(k <= K){
            a = true;
        }else{
            a = false;
        }

        k = 0;
        mid2 = mid+1;

        for(int i=0; i<N; i++){
            if(F[i]*A[i]>mid2){
                k += (F[i]*A[i]-mid2)/F[i];
                if((F[i]*A[i]-mid2)%F[i] != 0){
                    k++;
                }
            }
        }
        if(k <= K){
            b = true;
        }else{
            b = false;
        }

        if(a==true&&b==true){
            max = mid;
            mid = (mid+min)/2;
        }
        else if(a==false&&b==false){    
            min = mid2;
            mid = (mid+max)/2;
        }

        if(min == mid&&mid == max){
            t = 1;
            break;
        }
    }
    if(t == 0){
    cout << mid2;
    }else{
        cout << mid;
    }
}