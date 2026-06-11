#include<iostream>
#include<vector>

int main(void){
    std::vector<int> t(2), a(2);
    std::cin >> t[0] >> t[1] >> a[0] >> a[1];
    while(true){
	if(a[0] - t[1] <= 0){
	    std::cout << "Yes" << std::endl;
	    break;
	}
	a[0] = a[0] - t[1];
	if(t[0] - a[1] <= 0){
	    std::cout << "No" << std::endl;
	    break;
	}
	t[0] = t[0] - a[1];
    }
    return 0;
}

