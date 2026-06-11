#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%1000 !=0){
        cout<<((n/1000+1)*1000)-n<<endl;
    }
    else
        cout<< "0"<<endl;

    return 0;
}
