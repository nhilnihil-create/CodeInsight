#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> data;
    
    string S, T = "", W; int max_ = 0, c;
    
    while(cin >> S)
    {
        if(T.size() < S.size()) { T = S; }
        
        data.push_back(S);
    }
    
    sort(data.begin(), data.end());
    
    c = 1;
    
    if(data.size() != 1)
    {
        for(int i = 1; i < data.size(); i++)
        {
            if(data[i - 1] == data[i])
            {
                c++;
                
                if(max_  < c)
                {
                    max_ = c;
                    
                    W = data[i];
                }
            }
            else
            {
                c = 1;
            }
        }
    }
    else
    {
        W = S;
    }
    
    cout << W << ' ' << T << endl;
    
    return 0;
}