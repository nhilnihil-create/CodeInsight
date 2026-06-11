#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 4e6 + 77;

bool isPrime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i = 3 ; i*i <= n ; i += 2){
        if(n%i==0) return false;
    }
    return true;
}

int32_t main(){
    fast;
    int a , b; cin >> a >> b;
    set<int> A,B,C,Ans;
    for(int i = 1 ; i*i <= a ; ++i){
        if(a%i==0){
            A.insert(i);
            A.insert(a/i);
        }
    }
    for(int i = 1 ; i*i <= b ; ++i){
        if(b%i==0){
            B.insert(i);
            B.insert(b/i);
        }
    }
    for(int i : A) if(B.find(i)!=B.end()) C.insert(i);
    for(int i : C) if(isPrime(i)) Ans.insert(i);
    for(int i : C){
        bool ok = true;
        for(int j : Ans){
            if(__gcd(i,j)!=1){
                ok = false;
                break;
            }
        }
        if(ok) Ans.insert(i);
    }
    cout << Ans.size() << endl;
    return 0;
}