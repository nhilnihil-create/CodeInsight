#include<bits/stdc++.h>
using namespace std;
double total_odd_number(int n)
{
    if(n%2==0) return n/2;
    else return (n/2)+1;
}
int main(void)
{
    double n;
    cin>>n;
    double s = total_odd_number(n);
    cout<<fixed<<setprecision(10)<<s/n<<endl;

    return 0;
}
