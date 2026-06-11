#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int max_height=0;
    for (size_t i = 0; i < n; i++)
    {
        int h;
        cin>>h;
        if(i==0){
            max_height = h - 1;
        }
        else{
            if(h<max_height){
                cout<<"No"<<endl;
                return 0;
            }
            else if(h>max_height){
                max_height = h - 1;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}