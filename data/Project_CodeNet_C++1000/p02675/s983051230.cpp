#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;
int INF = 1 << 30;

int main(void){

    int N; cin>>N;

    if(N%10==3){
        cout<<"bon"<<endl;
    }else if(N%10==0 ||N%10==1 ||N%10==6 ||N%10==8){
        cout<<"pon"<<endl;
    }else {
        cout<<"hon"<<endl;
    }

}
