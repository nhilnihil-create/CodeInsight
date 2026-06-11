#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,w;
    cin>>n;
    
    if(n%2!=0){
        w = (n/2)+1;
        
        cout<<(double)w/(double)n<<endl;
    }else{
        cout<<0.5000000000<<endl;
    }
    return 0;
}
