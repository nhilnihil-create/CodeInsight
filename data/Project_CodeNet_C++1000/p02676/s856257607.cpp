#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    
    cin >> k;
    
    string arr;
    
    cin >> arr;
    
    if(k < arr.length())
    {
        for(int i=0; i<k; i++)
            cout << arr[i];
        
        cout << "...";
    }
    else
    {
        cout << arr;
    }

}
