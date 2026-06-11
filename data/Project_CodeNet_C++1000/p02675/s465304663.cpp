#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
//    int a[5]={2,4,5,7,9};
//    int b[4]={0,1,6,8};
//    int c[1]={3};
    cin>>n;
    //cout<<n;
    vector<int>m;
    while(n>0){
        int k=n%10;
        m.push_back(k);
        n/=10;
        //cout<<n<<endl;
    }
    //cout<<n<<endl;
    //m.push_back(n);
    for(int i=0;i<m.size();i++){
        //cout<<m[i]<<" ";
        if(m[i]==3){
            cout<<"bon"<<endl;
            break;
        }
        else if(m[i]==0||m[i]==1||m[i]==6||m[i]==8){
            cout<<"pon"<<endl;
            break;
        } else {
            cout<<"hon"<<endl;
            break;
        }
    }
}
