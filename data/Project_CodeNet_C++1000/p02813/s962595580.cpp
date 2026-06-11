#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision

using namespace std;
using p = pair<int,int>;
bool vectorcheck(vector<int>& x,vector<int>& y,int size){
            for (int i = 0; i < size; i++)
            {
                if(x[i] != y[i]) return false;
            }
            return true;
}
int main(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    vector<int> perm(n);
    for (int i = 0; i < n; i++) cin >>  a[i];
    for (int i = 0; i < n; i++) cin >>  b[i];
    for (int i = 1; i <= n; i++) perm[i-1] = i;    

    int dictnum=0,t=0,s=0;
    do{ 
        dictnum++;
        if(vectorcheck(perm,a,n)) t = dictnum;
        if(vectorcheck(perm,b,n)) s = dictnum;
    }while(next_permutation(perm.begin(),perm.end()));
    
    cout << abs(t-s) << endl;
    return 0;
}