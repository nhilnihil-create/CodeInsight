#include<iostream>
using namespace std;

int main()
{
    int N,p;
    cin>>N;
    int count = 0;

    for(int i=1;i<N;i++)
    {
        cin>>p;
        if(p!=i)
        {
            count++;
        }
    }
    if(count <=2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
