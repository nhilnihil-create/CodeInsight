#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    int p_a,p_b;cin>>p_a>>p_b;
    for(int i=0;i<n-2; i++){
        int p_c; cin >> p_c;
        if((p_a<p_b&&p_b<p_c)||(p_c<p_b&&p_b<p_a)) ans ++;
        p_a=p_b;p_b=p_c;
    }
    cout<< ans <<endl;
}