#include <iostream>         
                            
int main() {                
    int n, max, min = 0;
    long int sum = 0;
                            
    std::cin >> n;          
                            
    for(int i = 0; i < n; i++) {
        int num = 0;        
        std::cin >> num;    
        if(i == 0) {        
            max = min = sum = num;
        }else {             
            sum += num;     
            max = (num > max) ? num : max;
            min = (num < min) ? num : min;
        }                   
                            
    }                       
    std::cout << min << " " << max << " " << sum << std::endl;
    return 0;               
}