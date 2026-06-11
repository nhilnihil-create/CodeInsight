#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int A, B; cin>>A>>B;
    if(A>9 || B>9){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<A*B<<endl;
}
