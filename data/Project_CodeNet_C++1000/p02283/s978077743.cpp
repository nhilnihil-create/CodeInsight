#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct shu{
int key;
shu *left,*right,*parent;
};
shu* nil;
shu* root;
char s[100];
void charu(int k){
shu* y=nil;
shu* x=root;
shu* z;
z=new shu;
z->key=k;
z->left=nil;
z->right=nil;
while(x!=nil){
    y=x;
    if(z->key < x->key){
       x=x->left;
    }
    else x=x->right;
}
z->parent=y;
if(y==nil)root=z;
else {
      if(z->key < y->key){
         y->left=z;
         }
         else y->right=z;
}
}
void qianxu(shu* u){
    if(u==nil)return ;
    printf(" %d",u->key);
    qianxu(u->left);
    qianxu(u->right);
}
void zhongxu(shu* u){
    if(u==nil)return ;
    zhongxu(u->left);
    printf(" %d",u->key);
    zhongxu(u->right);
}
int main(){
int n;
int m;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%s",s);
    if(s[0]=='i'){
        scanf("%d",&m);
        charu(m);
    }
    else if(s[0]=='p'){
        zhongxu(root);
        printf("\n");
        qianxu(root);
        printf("\n");
    }
}
return 0;
}