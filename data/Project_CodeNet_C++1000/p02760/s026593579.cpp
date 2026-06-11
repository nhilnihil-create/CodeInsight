#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;
 


int main()
{
   
  
    vector<vector<int>>t(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> t[i][j];
        }
    }
    bool f[500] = {};
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        f[a]=1;
    }
    
    for (int i = 0; i < 3; i++) {
        
        if (f[t[0][i]]&& f[t[1][i]]&& f[t[2][i]]) {
            cout << "Yes" << endl;  
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {

        if (f[t[i][0]] && f[t[i][1]] && f[t[i][2]]) {
            cout << "Yes" << endl;
            return 0;
        }
    }int x = 0;
    for (int i = 0; i < 3; i++) {
        
       
           if(!f[t[i][i]]) x += t[i][i];
           
      
       
    }  if (!x) {
            cout << "Yes" << endl;
            return 0;
        }
    x = 0;
    for (int i = 0; i < 3; i++) {
       
        if(!f[t[2-i][i]])x += t[2-i][i];

        
    }if (!x) {
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;


    return 0;

}