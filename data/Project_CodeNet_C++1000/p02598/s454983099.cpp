#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    int left=0;
    int right=pow(10,9);
    while(right > left+1){
        int mid=(left+right)/2;
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=(a.at(i)+mid-1)/mid-1;
        }
        if(cnt<=k) right=mid;
        else left=mid;
    }
    cout << right << endl;
}