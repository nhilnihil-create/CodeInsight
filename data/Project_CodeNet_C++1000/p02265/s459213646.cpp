#include<cstdio>                                                                                                  
#include<list>                                                                                                    
#include<algorithm>                                                                                               
using namespace std;                                                                                              
                                                                                                                  
void printKeys(list<int> &keys) {                                                                                 
        printf("%d", *(keys.begin()) );                                                                           
        for(auto it=++(keys.begin()); it!=keys.end(); ++it) {                                                     
                printf(" %d", *it);                                                                               
        }                                                                                                         
        printf("\n");                                                                                             
}                                                                                                                 
                                                                                                                  
int main() {                                                                                                      
        list<int>       keys;                                                                                     
        int     n, key;                                                                                           
        char    com[20];                                                                                          
        const string    ins("insert"), del("delete"), delFirst("deleteFirst"), delLast("deleteLast");             
                                                                                                                  
        scanf("%d", &n);                                                                                          
        for(int i=0; i<n; ++i) {                                                                                  
                scanf("%s", com);                                                                                 
                if(ins == com) {                                                                                  
                        scanf("%d", &key);                                                                        
                        keys.push_front(key);                                                                     
                } else if(del == com) {                                                                           
                        scanf("%d", &key);                                                                        
                        auto it=find(keys.begin(), keys.end(), key);                                              
                        if(it != keys.end())    keys.erase(it);                                                   
                } else if(delFirst == com) {                                                                      
                        keys.pop_front();                                                                         
                } else if(delLast == com) {                                                                       
                        keys.pop_back();                                                                          
                }                                                                                                 
        }                                                                                                         
                                                                                                                  
        if(keys.size() == 0) {                                                                                    
                printf("\n");                                                                                     
                return 0;                                                                                         
        }                                                                                                         
                                                                                                                  
        printKeys(keys);                                                                                          
        return 0;                                                                                                 
}                                                                                                                 
                                                                                                                  