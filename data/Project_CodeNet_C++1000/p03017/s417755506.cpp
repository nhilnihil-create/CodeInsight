#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D;
    cin >> S;
    string ans;

    if (C < D)
    {
        string AD = S.substr(A - 1, D - A + 1);
        if (AD.find("##") == -1)
        {
            ans = "Yes";
        }else
        {
            ans = "No";
        }
        
    }else
    {
        string AC = S.substr(A - 1, C - A + 1);
        if (AC.find("##") == -1)
        {
            string BD = S.substr(B - 2, D - B + 3);
            if (BD.find("...") == -1)
            {
                ans = "No";
            }else
            {
                ans = "Yes";
            }
            
        }else
        {
            ans = "No";
        }
        
    }
    
    cout << ans << endl;

    return 0;
}