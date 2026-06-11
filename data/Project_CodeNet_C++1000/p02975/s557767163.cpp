// AGC 35 A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n; cin >> n;
    int a[n]; 
    inarray(a,n);
    sort(a,a+n);
    int c, zero = 0;
    vector<int> v;
    v.push_back(a[0]);
    if(a[0] == 0) zero++;
    for(int i = 1; i < n; i++){
        if(a[i] == 0) zero++;
        if(a[i-1] != a[i]){
            v.push_back(a[i]);
        }
    }
    c = v.size();
    if(c == 1){
        if(zero == n) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }else if(c == 2){
        if(zero == n/3 && n-(zero) == 2*n/3){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(c == 3){
        int w  = (v[0]^v[1]);
        w ^= v[2];
        if(w == 0){
            int c1 = 0, c2 = 0, c3 = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == v[0]) c1++;
                else if(a[i] == v[1]) c2++;
                else if(a[i] == v[2]) c3++;
            }
            if(c1 == c2 && c2 == c3) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            cout << "No" << endl;    
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}