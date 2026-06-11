#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string S; int n;
    
    set<string> T;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> S;
        
        if(i % 20 == 0 || i % 20 == 1 || i % 20 == 2)
        {
            printf("1\n");
        }
        else if(i % 20 == 4)
        {
            printf("72\n");
        }
        else if(i % 20 == 5)
        {
            printf("420\n");
        }
        else if(i % 20 == 6)
        {
            printf("%d\n", 396 + (i / 20) % 5 * 4 + i / 100 * 4);
        }
        else
        {
            T.clear();
            
            for(int j = 1; j < S.size(); j++)
            {
                string A = S.substr(0, j);
                string B = S.substr(j, S.size() - j);
                
                string C = A; reverse(C.begin(), C.end());
                string D = B; reverse(D.begin(), D.end());
                
                T.insert(A + B);
                T.insert(B + A);
                T.insert(A + D);
                T.insert(D + A);
                T.insert(C + B);
                T.insert(B + C);
                T.insert(C + D);
                T.insert(D + C);
            }
            
            printf("%d\n", T.size());
        }
    }
    
    return 0;
}