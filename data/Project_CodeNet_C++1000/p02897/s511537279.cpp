#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
float count1=0.0;
cin>>n;
if(n>=1&&n<=100){
    for(int i=1;i<=n;i++){
        if(i%2!=0)
            count1+=1;
    }
    cout<<count1/n<<endl;
}

return 0;}
