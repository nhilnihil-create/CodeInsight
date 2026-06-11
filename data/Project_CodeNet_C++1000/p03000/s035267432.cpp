#include<iostream>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int c=1,sum=0;
    while(n--){
        int temp;
        cin>>temp;
        sum+=temp;
        if(sum<=x) c++;
        else break;
    }
    cout<<c<< "\n";
    return 0;
}
