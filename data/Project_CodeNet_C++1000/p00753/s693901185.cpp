#include<iostream>
#include<vector>

using namespace std;

int main(void) {

        int in; 

        vector<int> list;

        for(int i=2;i<=123456;i++) {
                bool sosu = true;
                for(int &n: list) {
                        if(i%n==0) {
                                sosu = false;
                                break;
                        }   
                }   
                if(sosu) {
                  list.push_back(i);
                }   
                    
        }   

        while(cin >> in && in) {

                int count=0;
                for(int i=in+1;i<=2*in;i++) {
                        bool sosu = true;
                        for(int &n: list) {
                                if(n>=i) break;
                                if(i%n==0) {
                                        sosu = false;
                                        break;
                                }   
                        }   
                        if(sosu) count++;
                }   
                cout << count << endl;
        }   
            
        return 0;
}