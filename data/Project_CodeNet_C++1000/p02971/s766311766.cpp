#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int MAX=0, pre_MAX=0;
    int max_ids=0, pre_ids=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>MAX){
            pre_MAX = MAX; pre_ids = max_ids;
            MAX = a[i];   max_ids = i;
        }else if(a[i]==MAX){
            pre_MAX = MAX;  pre_ids = i;
        }else if(a[i] > pre_MAX){
            pre_MAX = a[i]; pre_ids = i;
        }
    } 

    for(int i=0; i<n; i++){
        if(i == max_ids)
            cout << pre_MAX << endl;
        else 
            cout << MAX << endl;
    }
    return 0;
}