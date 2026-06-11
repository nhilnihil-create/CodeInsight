#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    if(n==0){
        cout<<x<<endl;
    }else{
        vector<bool>a(102);
        int l;
        for(int i=0;i<n;i++){
            cin>>l;
            a[l]=true;
        }
        for(int i=0;i<=100;i++){
            if(a[x-i]==false){
                cout<<x-i<<endl;
                return 0;
            }else if(a[x+i]==false){
                cout<<x+i<<endl;
                return 0;
            }
        }
    }
    return 0;

}