#include<bits/stdc++.h>
using namespace std;
int main(){
        int n; cin>>n;
        int rem=n%10;
        if(rem==3) cout<<"bon"<<endl;
        else if(rem==0||rem==1||rem==6||rem==8) cout<<"pon"<<endl;
        else cout<<"hon"<<endl;
}
