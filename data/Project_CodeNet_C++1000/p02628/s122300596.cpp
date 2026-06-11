#include <iostream>

using namespace std;
int p[10001],price,c;

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin >> price;
        p[price]++;
    }
    price=0;
    while (k!=0){
        price++;
        for (;p[price]!=0; p[price]--,c+=price,k--)
            if (k==0)
                break;
    }
    cout<<c;
    return 0;
}