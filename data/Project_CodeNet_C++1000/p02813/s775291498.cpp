#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,an=-1,bn=-1,k=0;
    cin>>n;
    string c,s="12345678";
    vector<char>a(1000);
    vector<char>b(1000);
    for(int i=0;i<n;i++){
        c+=s[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    while(an==-1||bn==-1){
        for(int i=0;i<n+1;i++){
            if(a[i]!=c[i]){
                break;
            }
            if(i==n){
                an=k;
            }
        }
        for(int i=0;i<n+1;i++){
            if(b[i]!=c[i]){
                break;
            }
            if(i==n){
                bn=k;
            }
        }
        
        k++;
        std::next_permutation(c.begin(),c.end());
    }
    cout<<abs(an-bn)<<endl;
    return 0;
}
