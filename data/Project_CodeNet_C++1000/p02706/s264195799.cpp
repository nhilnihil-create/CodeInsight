#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int sum = 0;
    while(m--){
        int a;
        cin>>a;
        sum+=a;
    }
    if(n-sum>=0){
        cout<<n-sum<<endl;
    }
        else{
        cout<<-1<<endl;
    }

}
