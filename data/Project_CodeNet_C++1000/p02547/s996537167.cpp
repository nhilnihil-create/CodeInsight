//
//  main.cpp
//  179_B
//
//  Created by Parsa Alimohammadi on 6/31/1399 AP.
//  Copyright © 1399 Parsa Alimohammadi. All rights reserved.
//

#define ll long long
#define ldu long double
#define pb push_back
#define pop pop_back()
#define du double
// --------------------------------------------------------------
/*
 #define paii pair<int , int>
 #define pasi pair<string,int>
 #define F first
 #define S second
 */
// --------------------------------------------------------------
#define input_txt freopen("input.txt" , "r" , stdin);
#define output_txt freopen("output.txt" , "w" , stdout);
#define Shield  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout << "REAlY!! ";
// #define ashar cout << fixed << setprecision(tedad ashaar) << adadet ke bayad double bashe << endl;

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
// #include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 * 1 + 2;
int n;
bool ans = false;

int main()
{
    Shield
    cin >> n;
    for (int d1,d2,g=0; n>0; n--)
    {
        cin >> d1 >> d2;
        if(d1==d2)
            g++;
        else
            g =0 ;
        if (g==3)
            ans= true;
    }
    
    ans == true ? cout << "Yes" : cout << "No";
    return 0;
}

