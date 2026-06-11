#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long int ll; 

int main(void)
{
	ll x,k,d;
    cin >> x >> k >> d;

    ll mul = (abs(x))/d;
    /// if x == 0,it will go in else
    
    if(k < mul)
    {
        if(x < 0)
            x += k*d;
        else if(x > 0)
            x -= k*d;
        else if(x == 0)
        {
            if(k%2 == 1)
                x += d;
        }
        cout << abs(x) << endl;
    }
    else if(k > mul)
    {
        if(x < 0)
        {
            x += mul*d;
            k -= mul;
            if(k%2 == 1) //odd no of steps left
                cout << abs(x+d) << endl;
            else
                cout << abs(x) << endl;
        }
        else if(x > 0)
        {
            x -= mul*d;
            k -= mul;
            if(k%2 == 1) //odd no of steps left
                cout << abs(x-d) << endl;
            else
                cout << abs(x) << endl;
        }
        else if(x == 0)
        {
            if(k%2 == 1) 
                cout << abs(x+d) << endl;
            else
                cout << abs(x) << endl;   
        }
    }
    else if(k == mul)
    {
        if(x > 0)
            x -= mul*d;
        else if(x < 0)
            x += mul*d;
        else if(x == 0)
        {
            if(k != 0 && k%2 == 1)
                x = x+d;
        }
        cout << abs(x) << endl;        
    }

	return 0;
}