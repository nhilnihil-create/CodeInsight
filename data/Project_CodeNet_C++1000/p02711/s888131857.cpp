#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n!=0)
    {
        int digi1 = n%10;
        if(digi1==7)
        {
            cout << "Yes" << endl;
            break;
        }
        n = n/10;
        if(n==0 && digi1 != 7){
            cout << "No" << endl;
            break;
        }
        //cout << digi1 << endl;
    }

    return 0;
}
