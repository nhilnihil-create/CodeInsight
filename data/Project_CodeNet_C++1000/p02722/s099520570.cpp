#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n;
    cin >> n;
    int cnt = 0;
    set<int> s;
    for(int i = 1;i<=sqrt(n);i++){
        int n1 = n;
        int c = 0;
        if(i > 1){
        while(n1%i==0){
            n1 /= i;
            c++;
        }
        if(n1%i == 1){ s.insert(i);cnt++;}
        }
        n1 = n;
        c = 0;
        int i1 = n1/i;
        if(i1 > 1){
        while(n1%i1==0){
            n1 /= i1;
            c++;
        }
        if(n1%i1 == 1){ s.insert(i1);cnt++;}
        }
    }
    --n;
    for(int i = 1;i<=sqrt(n);i++){
        int n1 = n;
        int c = 0;
        if(i > 1){
        while(n1%i==0){
            n1 /= i;
            c++;
        }
        if(c){ s.insert(i);cnt++;}
        }
        n1 = n;
        c = 0;
        int i1 = n1/i;
        if(i1 > 1){
        while(n1%i1==0){
            n1 /= i1;
            c++;
        }
        if(c){ s.insert(i1);cnt++;}
        }
    }

    cout << s.size();
}
