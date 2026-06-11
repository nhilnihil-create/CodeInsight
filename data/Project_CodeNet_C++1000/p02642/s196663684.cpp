#include<iostream>
#include<vector>
#include<algorithm>

const static int INF = 1001001001;

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
	std::cin >> a[i];	
    }
    std::sort(a.begin(), a.end());

    int MAX = a[n-1];
    std::vector<int> acnt(MAX+1);
    acnt[0] = INF;

    for(int i = 0; i < n; i++){
	if(i != 0 && a[i] == a[i-1]){
	    acnt[a[i]]++;
	}
	for(int j = a[i] * 2; j <= MAX; j = j + a[i]){
	    acnt[j]++;
	}
    }


    int cnt = 0;
    for(int i = 0; i < n; i++){
	if(acnt[a[i]] == 0) cnt++;
    }

    std::cout << cnt << std::endl;

    return 0;
}
