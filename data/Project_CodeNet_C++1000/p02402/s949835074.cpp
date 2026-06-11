#include <iostream>

int main(int argc, const char * argv[])
{

    // insert code here...
    int n;
    std::cin >> n;
    long int min = 1000001;
    long int max = -1000001;
    long long int sum = 0;
    
    for (int i=0; i<n; i++){
        int val;
        std::cin >> val;
        if (min > val){
            min = val;
        }
        if (max < val){
            max = val;
        }
        sum += val;
    }
    std::cout << min << " " << max << " " << sum << std::endl;
    return 0;
}