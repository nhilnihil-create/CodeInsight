#include<vector>
#include<string>
#include<iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

int main(){
    fast;
    int n,i,answer=0;
    cin >> n;
    int a[n],b[n],c[n-1];
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    for(i=0;i<n-1;i++){
        cin >> c[i];
    }
    answer = b[a[0]-1];
    for(i=1;i<n;i++){
        answer += b[a[i]-1];
        if(a[i] == a[i-1]+1){
            answer += c[a[i-1]-1];
        }
    }
    cout << answer;
}
