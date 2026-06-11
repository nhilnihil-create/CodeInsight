#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> len_el(n);
    long long length = 0;
    for(int i=0; i<n; i++){
        cin >> len_el[i]; 
        length += len_el[i];
    }
    long long inf=0,sup=0;
    int i = 0;
    while(true){
        sup += len_el[i];
        if(sup*2>=length) break;
        inf += len_el[i];
        i++;
    }
    long long inf_red=length-inf;
    long long sup_res=length-sup;
    long long ans = min(inf_red-inf, sup-sup_res);
    cout << ans << endl;
}