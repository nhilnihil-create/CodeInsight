#include <iostream>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> sunuke(n);
    for (int i = 0; i < k; i++)
    {
        int d;
        std::cin >> d;
        for (int j = 0; j < d; j++)
        {
            int a;
            std::cin >> a;
            sunuke[a - 1] = 1;
        }
    }
   
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sunuke[i] == 0)
        {
            count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}