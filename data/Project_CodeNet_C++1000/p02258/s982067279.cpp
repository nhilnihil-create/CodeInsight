#include <queue>
#include <cstdio>
#include <limits>
#include <algorithm>
 
int main()
{
    int n, MAX = std::numeric_limits<int>::min();
    
    std::queue<int> R;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        
        scanf("%d", &temp);
        
        R.push(temp);
        
        MAX = R.size() > 1 ? std::max(R.back() - R.front(), MAX) : MAX;
 
        if (R.back() < R.front())
        {
            while (R.size() > 1)
            {
                R.pop();
            }
        }
    }
 
    printf("%d\n", MAX);
 
    return 0;
}
 
// Time : O( 2n )