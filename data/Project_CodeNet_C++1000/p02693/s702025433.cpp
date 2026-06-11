#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;

    int a,b;
    cin>>a>>b;

    if(b-a +1 >= k){
        cout<<"OK"<<endl;
    }
    else{
        for(int i = a;i<=b;i++){
            if(i % k == 0){
                cout<<"OK"<<endl;
                break;
            }
            if(i == b){
                cout<<"NG"<<endl;
            }
        }
    }
}
