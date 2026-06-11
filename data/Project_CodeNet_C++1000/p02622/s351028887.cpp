#include <iostream>

using namespace std;

int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
}

int dp(string x,string y, int m) 
{ 
    int count(0);
    for (int i = 0; i <= m; i++) { 
        if (x[i] != y[i]) count++;
    }
    return count;
} 

int main()
{
    string x,y;
    cin>>x>>y;
    cout<<dp(x,y,x.length());
}