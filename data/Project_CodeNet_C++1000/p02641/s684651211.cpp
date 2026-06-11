#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){


int X,N;
cin >> X >> N;

vector < int > v;
int a;

for(int i =0 ; i<N; i++)
{
    cin >> a;
    v.push_back(a - X);
}

//sort(v.begin(), v.end());

vector<int>::iterator itr;
itr = find(v.begin(), v.end(), 0);
if (itr == v.end()) 
{
    cout << X;
    return 0;
}

for(int i =1 ; i<100; i++)
{
    vector<int>::iterator itr1,itr2;
    itr1= find(v.begin(), v.end(), -i);
    if(itr1== v.end())
    {
        cout << X - i;
        return 0;
    }

    itr2= find(v.begin(), v.end(), i);
    if(itr2== v.end())
    {
        cout << X + i;
        return 0;
    }


}




    return 0;
}


