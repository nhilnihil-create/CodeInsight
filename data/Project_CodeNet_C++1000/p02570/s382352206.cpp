#include <iostream>
using namespace std;

void solve(){

    int D ,T ,S;
    cin>>D>>T>>S;

    if(D<= (S*T) ){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

int main()
{
    int TestCases=1;
    while(TestCases>0){
        solve();
        TestCases--;
    }

    return 0;
}
