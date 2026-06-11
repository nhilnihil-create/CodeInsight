
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>


using namespace std;

typedef long long ll;
typedef vector<vector<int> > Graph;


int main() {
    
    string S;
    cin>>S;
    deque<char> dq1,dq2;
    
    int count=0;
    

    
    int Q;
    cin>>Q;
    int F;
    char C;
    
    for(int i=0;i!=Q;++i){
        int T;
        cin>>T;
        switch(T){
            case 1:
                ++count;
                break;
            case 2:
                cin>>F;
                cin>>C;
                if(count%2==0){
                    
                    switch(F){
                        case 1:
                            dq1.push_front(C);
                            break;
                        case 2:
                            dq2.push_back(C);
                            break;
                            
                    }
                
                }else{
                    switch(F){
                        case 1:
                            dq2.push_back(C);
                            break;
                        case 2:
                            dq1.push_front(C);
                            break;
                    }
                }
        }
        
    }
    
    if(count%2==0){
        for(deque<char>::iterator itr=dq1.begin();itr!=dq1.end();++itr){
            cout<<*itr;
        }
        cout<<S;
        for(deque<char>::iterator itr=dq2.begin();itr!=dq2.end();++itr){
            cout<<*itr;
        }
        cout<<endl;
    }else{
        reverse(dq1.begin(),dq1.end());
        reverse(dq2.begin(),dq2.end());
        reverse(S.begin(),S.end());
        for(deque<char>::iterator itr=dq2.begin();itr!=dq2.end();++itr){
                   cout<<*itr;
        }
        cout<<S;
         for(deque<char>::iterator itr=dq1.begin();itr!=dq1.end();++itr){
                  cout<<*itr;
              }
             cout<<endl;
        
        
    }
    

}
    