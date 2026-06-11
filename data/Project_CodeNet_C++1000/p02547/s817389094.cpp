#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    int N,a,b;
    cin >>N;

    vector <vector <int>> vec(N, vector<int>(2));
    for(int i = 0;i<N;i++)
    {
        cin >>vec.at(i).at(0) >>  vec.at(i).at(1);
    }

    int count = 0;

    for(int i = 0;i<N;i++)
    {
        if(vec.at(i).at(0) == vec.at(i).at(1))
        {
            count ++;
        }else
        {
            count =0;
        }

        if(count == 3)
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return  0;
}