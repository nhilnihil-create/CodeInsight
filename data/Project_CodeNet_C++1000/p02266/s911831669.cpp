#include<iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    char str[20005];
    scanf("%s",str);
    stack<int> s1; // sto#include<iostream>re the index of String
    stack<pair<int, int>> s2; // left endpoint and area of all covering area
    //rintf("%d\n",strlen(str));
    int size = strlen(str);
    int total = 0; // total area;
    for(int i = 0; i<size; i++){// i is index of ele
        //for each ele
        //\ -> push
        if(str[i]=='\\'){
            s1.push(i);
        } else if(str[i]=='/' && s1.size()>0) {// / && (there is \)-> pop
            int j = s1.top();  // \ index
            s1.pop();
            int area = i - j; //cal current area(for each \/)
            total += area; // cal total
            //deal wwith another stack
            while(s2.size()>0 && s2.top().first>j){ // 2>1
                area += s2.top().second; s2.pop();
            }
            s2.push(make_pair(j,area)); // j means 
        }
        
    }
    printf("%d\n",total);
    
    int count = s2.size();
    if(count == 0) printf("%d",count);
    else printf("%d ",count);
    int arr[count+1];
    int i = 0;
    while(!s2.empty()){
        int sec = s2.top().second;
        arr[i++] = sec;
        s2.pop();
        //printf("%d ", sec);
    }//printf("\n");
    //printf("%s", str);
    for( i = count-1; i>=0; i--){\
      if(i!=0) printf("%d ", arr[i]);
      else printf("%d", arr[i]);
    
    }printf("\n");
  //printf("%.6f %.6f\n", M_PI*a*a,M_PI*2.0*a);
  return 0;
}

