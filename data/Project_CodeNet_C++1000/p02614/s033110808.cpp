#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int n, w, k;
int a[6][6];


int allCount, hits;



void calc(int x, int y){


    int count = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < w; j++)
        {
            //cout << "y " << y << "j " << j << ".. " << (y&(1<<j)) << endl;
            if((y&(1<<j)) > 0 || (x&(1<<i)) > 0){
                count += a[i][j];
            }
        }
    }
    
    if(allCount - count == k) hits++;
}


void solve(){
    

    cin >> n >> w >> k;

    string s;
    allCount = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int j = 0;
        for (char c : s)
        {
            if(c == '#'){
                a[i][j] = 1;
                allCount++;
            } 
            else a[i][j] = 0;
            j++;
        }
        

        
    }
    
    hits = 0;

    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < (1<<w); j++)
        {
            calc(i,j);
        }
        
        
    }
    
    cout << hits <<endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}